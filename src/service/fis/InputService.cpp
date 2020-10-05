#include "continental/fuzzy/service/fis/InputService.h"

using namespace continental::fuzzy::domain::fis::variable;
using namespace continental::fuzzy::service::fis;

namespace continental {
namespace fuzzy {
namespace service {
namespace fis {

InputService::InputService()
{

}

InputService::~InputService()
{

}

void InputService::createFromFisBlock(const std::list<QString> &fisInputList)
{
    // Armazena as informações sobre as funções de pertinência
    std::map<int, QString> membershipFunctionsMap = std::map<int, QString>();

    for (QString line : fisInputList)
    {
        // Divide a string das linhas no sinal de "=" em nome e valor
        QStringList splitLine = line.split("=");
        const QString systemField = splitLine[0];
        const QString systemFieldValue = splitLine[1].replace("'","");

        // Preenche os atributos da classe baseado nas  entradas do arquivo .fis
        if (systemField == "Name")
        {
            m_input.setName(systemFieldValue);
        }
        else if (systemField == "Range")
        {
            int rangeValuesSize = systemFieldValue.size();

            // Remove os colchetes
            QString rangeValues = systemFieldValue.mid(1, rangeValuesSize - 2);
            // Separa os valores
            QStringList rangeValuesSplitted = rangeValues.split(" ");
            std::pair<float, float> rangePair = std::pair<float, float>();
            rangePair.first = rangeValuesSplitted[0].toFloat();
            rangePair.second = rangeValuesSplitted[1].toFloat();
            m_input.setRange(rangePair);
        }
        else if (systemField == "NumMFs")
        {
            m_input.setNumMfs(systemFieldValue.toInt());
        }
        else if (systemField.left(2) == "MF")
        {
            int fieldSize = systemField.size();
            int mfsNumber = systemField.right(fieldSize - 2).toInt();
            membershipFunctionsMap.insert(std::pair<int, QString>(mfsNumber, systemFieldValue));
        }
        else
        {
            throw std::exception("Entrada " + systemField.toLocal8Bit() + " não é válida para o bloco de Inputs!");
        }
    }

    // Verifica se todos os atributos da variável foram preenchidos
    if (m_input.getName() == "")
    {
        throw std::exception("O nome da variável não foi informado!");
    }
    else if ((static_cast<int>(m_input.getRange().first * 1000) == 0) && (static_cast<int>(m_input.getRange().second * 1000) == 0))
    {
        throw std::exception("A amplitude do conjunto da variável não foi informada!");
    }
    else if (m_input.getNumMfs() == 0)
    {
        throw std::exception("O número de funções de pertinência da variável não foi informado!");
    }

    // Verifica se a quantidade de funções de pertinência está correta
    int sizeMfsMap = static_cast<int>(membershipFunctionsMap.size());
    if (sizeMfsMap == m_input.getNumMfs())
    {
        for (auto const& item : membershipFunctionsMap)
        {
            // Remover aspas e extrair nome de identificação
            QString rawItem = item.second;
            QStringList itemSplitted = rawItem.replace("'","").split(":");
            QString mfName = itemSplitted[0];

            // Atribui o nome da função
            QStringList functionSplitted = itemSplitted[1].split(",");
            QString functionName = functionSplitted[0];
            QString functionValues = functionSplitted[1];

            MembershipFunctionService mfService = MembershipFunctionService();
            mfService.createInputMembershipFunction(mfName, functionName, functionValues);
            m_input.addInputMfs(item.first, mfService.getInputMembershipFunction());
        }
    }
    else
    {
        throw std::exception("Quantidade de funções de pertinência para a variável " + m_input.getName().toLocal8Bit() + " é diferente do número de funções de pertinência informado no bloco!");
    }
}

Input InputService::getInput() const
{
    return m_input;
}

void InputService::setInput(const Input &input)
{
    m_input = input;
}


}
}
}
}
