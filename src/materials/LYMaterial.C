/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/
#include "LYMaterial.h"

template <>
InputParameters
validParams<LYMaterial>()
{
  InputParameters params = validParams<Material>();

  params.addRequiredCoupledVar("ly_u", "The variable to use as u");

  params.addRequiredParam<Real>("kappa", "The kappa");

  return params;
}

LYMaterial::LYMaterial(const InputParameters & parameters)
  : Material(parameters),
    _input_kappa(getParam<Real>("kappa")),
    _grad_ly_u(coupledGradient("ly_u")),
    _k(declareProperty<Real>("k")),
    _kappa(declareProperty<Real>("kappa"))
{
}

void
LYMaterial::computeQpProperties()
{
  _k[_qp] = 5

  _kappa[_qp] = _input_kappa;
}
