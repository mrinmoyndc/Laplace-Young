#ifndef LYFORCE_H
#define LYFORCE_H

#include "Kernel.h"

class LYForce;

template <>
InputParameters validParams<LYForce>();

class LYForce : public Kernel
{
public:
  LYForce(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;

  virtual Real computeQpJacobian() override;

private:
  const MaterialProperty<Real> & _kappa;
};

#endif /* LYFORCE_H */
