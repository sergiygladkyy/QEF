#include "scriptmap.h"

QScriptValue ScriptMapToScriptValue(QScriptEngine* eng, const ScriptMap& map)
{
  QScriptValue a = eng->newObject();
  ScriptMap::const_iterator it(map.begin());
  for(; it != map.end(); ++it)
  {
    QString prop = it.key();
    prop.replace(' ', '_');
    a.setProperty(prop, qScriptValueFromValue(eng, it.value()));
  }
  return a;
}

void ScriptMapFromScriptValue( const QScriptValue& value, ScriptMap& map)
{
  QScriptValueIterator itr(value);
  while(itr.hasNext())
  {
    itr.next();
    map[itr.name()] = qscriptvalue_cast<ScriptMap::mapped_type>(itr.value());
  }
}

void registerScriptMetaTypes(QScriptEngine* engine)
{
  qScriptRegisterMetaType<ScriptMap>(engine, ScriptMapToScriptValue, ScriptMapFromScriptValue);
}
