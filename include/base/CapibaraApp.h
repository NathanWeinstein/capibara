#ifndef CAPIBARAAPP_H
#define CAPIBARAAPP_H

#include "MooseApp.h"

class CapibaraApp;

template<>
InputParameters validParams<CapibaraApp>();

class CapibaraApp : public MooseApp
{
public:
  CapibaraApp(InputParameters parameters);
  virtual ~CapibaraApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* CAPIBARAAPP_H */
