#ifndef LYDIFF_H
#define LYDIFF_H

#include "Diffusion.h"

class LYDiff;

template <>
InputParameters validParams<LYDiff>();

/**
 * This kernel implements the Laplacian operator:
 * $\nabla u \cdot \nabla \phi_i$
 */
class LYDiff : public Diffusion
{
public:
  LYDiff(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;

  virtual Real computeQpJacobian() override;

private:
  const MaterialProperty<Real> & _k;
};

#endif /* LYDIFF_H */
