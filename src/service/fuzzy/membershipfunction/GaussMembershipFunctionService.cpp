#include "continental/fuzzy/service/fuzzy/membershipfunction/GaussMembershipFunctionService.h"

namespace continental {
namespace fuzzy {
namespace service {
namespace fuzzy {
namespace membershipfunction {

GaussMembershipFunctionService::GaussMembershipFunctionService()
{

}

GaussMembershipFunctionService::~GaussMembershipFunctionService()
{

}

double GaussMembershipFunctionService::calculeGaussMf(double xValue, double mean, double sigma)
{
    // Retorna o valor de y de uma curva gaussiana utilizando a média e o desvio padrão informados.
    return std::exp((-(xValue - mean) * (xValue - mean)) / (2.0 * sigma * sigma));
}

}
}
}
}
}
