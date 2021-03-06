
#ifndef SCANTAILOR_UNITSPROVIDER_H
#define SCANTAILOR_UNITSPROVIDER_H

#include <foundation/NonCopyable.h>
#include <list>
#include <memory>
#include "UnitsObserver.h"

class Dpi;

class UnitsProvider {
  DECLARE_NON_COPYABLE(UnitsProvider)
 private:
  UnitsProvider();

 public:
  static UnitsProvider* getInstance();

  Units getUnits() const;

  void setUnits(Units units);

  void attachObserver(UnitsObserver* observer);

  void detachObserver(UnitsObserver* observer);

  void convertFrom(double& horizontalValue, double& verticalValue, Units fromUnits, const Dpi& dpi) const;

  void convertTo(double& horizontalValue, double& verticalValue, Units toUnits, const Dpi& dpi) const;

 protected:
  void unitsChanged();

 private:
  static std::unique_ptr<UnitsProvider> m_instance;

  std::list<UnitsObserver*> m_observers;
  Units m_units;
};


#endif  // SCANTAILOR_UNITSPROVIDER_H
