#include "CapibaraApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<CapibaraApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

CapibaraApp::CapibaraApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  CapibaraApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  CapibaraApp::associateSyntax(_syntax, _action_factory);
}

CapibaraApp::~CapibaraApp()
{
}

// External entry point for dynamic application loading
extern "C" void CapibaraApp__registerApps() { CapibaraApp::registerApps(); }
void
CapibaraApp::registerApps()
{
  registerApp(CapibaraApp);
}

// External entry point for dynamic object registration
extern "C" void CapibaraApp__registerObjects(Factory & factory) { CapibaraApp::registerObjects(factory); }
void
CapibaraApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void CapibaraApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { CapibaraApp::associateSyntax(syntax, action_factory); }
void
CapibaraApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
