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

#include "LYForce.h"

template <>
InputParameters
validParams<LYForce>()
{
  InputParameters params = validParams<Kernel>();
  params.addClassDescription("The Force part of the Laplace-Young Problem");
  return params;
}

LYForce::LYForce(const InputParameters & parameters) :
    Kernel(parameters),
    _kappa(getMaterialProperty<Real>("kappa"))
{}

Real
LYForce::computeQpResidual()
{
  return _kappa[_qp] * _u[_qp] * _test[_i][_qp];
}

Real
LYForce::computeQpJacobian()
{
  return _kappa[_qp] * _phi[_j][_qp] * _test[_i][_qp];
}
