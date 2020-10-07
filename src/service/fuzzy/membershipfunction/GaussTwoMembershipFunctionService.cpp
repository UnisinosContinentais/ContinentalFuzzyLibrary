#include "continental/fuzzy/service/fuzzy/membershipfunction/GaussTwoMembershipFunctionService.h"

using namespace continental::fuzzy::service::fuzzy::membershipfunction;

namespace continental {
namespace fuzzy {
namespace service {
namespace fuzzy {
namespace membershipfunction {

GaussTwoMembershipFunctionService::GaussTwoMembershipFunctionService()
{

}

GaussTwoMembershipFunctionService::~GaussTwoMembershipFunctionService()
{

}

double GaussTwoMembershipFunctionService::calculeTwoGaussMf(double xValue,
                                                            double meanOne,
                                                            double sigmaOne,
                                                            double meanTwo,
                                                            double sigmaTwo)
{
    // Se o valor de x estiver entre as duas médias ele será igual a 1.
    if ((xValue >= meanOne) && (xValue <= meanTwo))
    {
        return 1.0;
    }

    // Inicializa as duas curvas gaussianas com valor 1
    float leftGauss = 1;
    float rightGauss = 1;

    // Se o valor de x for menor que a primeira média calcula o valor de uma curva gaussiana usando a primeira média e desvio padrão.
    if (xValue < meanOne)
    {
        leftGauss = GaussMembershipFunctionService::calculeGaussMf(xValue, meanOne, sigmaOne);
    }

    // Se o valor de x for maior que a segunda média calcula o valor de uma curva gaussiana usando a segunda média e desvio padrão.
    if (xValue > meanTwo)
    {
        rightGauss = GaussMembershipFunctionService::calculeGaussMf(xValue, meanTwo, sigmaTwo);
    }

    return leftGauss * rightGauss;
}

}
}
}
}
}
