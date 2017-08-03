#ifndef LYAPP_H
#define LYAPP_H

#include "MooseApp.h"

class LyApp;

template<>
InputParameters validParams<LyApp>();

class LyApp : public MooseApp
{
public:
  LyApp(InputParameters parameters);
  virtual ~LyApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* LYAPP_H */
