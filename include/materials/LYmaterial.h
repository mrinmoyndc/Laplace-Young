#ifndef LYMATERIAL_H
#define LYMATERIAL_H

#include "Material.h"

// A helper class from MOOSE that linear interpolates x,y data
#include "LinearInterpolation.h"

class LYMaterial;

template <>
InputParameters validParams<LYMaterial>();

/**
 * Material objects inherit from Material and override computeQpProperties.
 *
 * Their job is to declare properties for use by other objects in the
 * calculation such as Kernels and BoundaryConditions.
 */
class LYMaterial : public Material
{
public:
  LYMaterial(const InputParameters & parameters);

protected:
  /**
   * Necessary override.  This is where the values of the properties
   * are computed.
   */
  virtual void computeQpProperties() override;

  const Real & _input_kappa;

  const VariableGradient & _grad_ly_u;

  MaterialProperty<Real> & _k;

  MaterialProperty<Real> & _kappa;
};

#endif // LYMATERIAL_H
