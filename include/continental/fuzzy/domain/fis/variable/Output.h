#ifndef CONTINENTAFUZZY_DOMAIN_FUZZY_VARIABLE_OUTPUT_H
#define CONTINENTAFUZZY_DOMAIN_FUZZY_VARIABLE_OUTPUT_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/domain/fis/Variable.h"
#include <QString>
#include <list>

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace variable {

class CONTINENTALFUZZY_EXPORT_DECL Output : public Variable
{

public:
    /// Construtor.
    Output();

    QString getName() const;
    void setName(const QString &name);

    std::list<float> getRange() const;
    void setRange(const std::list<float> &value);

    int getNumMfs() const;
    void setNumMfs(int numMfs);

private:
    QString m_name;
    std::list<float> range;
    int m_numMfs;
    //std::map<int, MembershipFunction> m_mfs;
};

}
}
}
}
}

#endif // CONTINENTAFUZZY_DOMAIN_FUZZY_VARIABLE_OUTPUT_H
