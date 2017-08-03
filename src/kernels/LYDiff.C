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

#include "LYDiff.h"

template <>
InputParameters
validParams<LYDiff>()
{
  InputParameters params = validParams<Diffusion>();
  params.addClassDescription("The Diffusion part of the Laplace-Young Problem");
  return params;
}

LYDiff::LYDiff(const InputParameters & parameters) :
    Diffusion(parameters),
    _k(getMaterialProperty<Real>("k"))
{}

Real
LYDiff::computeQpResidual()
{
  return _k[_qp] * Diffusion::computeQpResidual();
}

Real
LYDiff::computeQpJacobian()
{
  return _k[_qp] * Diffusion::computeQpJacobian();
}
