/*
* Developed by UNISINOS - Projeto Continentais and Petrobras
* author: Rudi C. C. Modena
* email: rmodena@unisinos.br
* date: October, 2020
*/
#ifndef CONTINENTAL_FUZZY_SERVICE_FUZZY_MEMBERSHIPFUNCTION_TRAPEZOIDALMEMBERSHIPFUNCTIONSERVICE_H
#define CONTINENTAL_FUZZY_SERVICE_FUZZY_MEMBERSHIPFUNCTION_TRAPEZOIDALMEMBERSHIPFUNCTIONSERVICE_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/service/fuzzy/membershipfunction/TriangularMembershipFunctionService.h"

namespace continental {
namespace fuzzy {
namespace service {
namespace fuzzy {
namespace membershipfunction {


class CONTINENTALFUZZY_EXPORT_DECL TrapezoidalMembershipFunctionService
{

public:
    /// Construtor.
    TrapezoidalMembershipFunctionService();

    /// Destrutor.
    ~TrapezoidalMembershipFunctionService();

    static double calculeTrapezoidalMf(double xValue,
                                       double pointA,
                                       double pointB,
                                       double pointC,
                                       double pointD);
};

}
}
}
}
}

#endif CONTINENTAL_FUZZY_SERVICE_FUZZY_MEMBERSHIPFUNCTION_TRAPEZOIDALMEMBERSHIPFUNCTIONSERVICE_H
