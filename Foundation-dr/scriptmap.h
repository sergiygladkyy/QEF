#ifndef SCRIPTMAP_H
#define SCRIPTMAP_H
#include <QtGui>
#include <QtScript>

class ScriptMap : public QMap<QString, QVariant> {
}; // work around because typedefs do not register correctly.
Q_DECLARE_METATYPE(ScriptMap);

QScriptValue ScriptMapToScriptValue(QScriptEngine* eng, const ScriptMap& map);
void ScriptMapFromScriptValue( const QScriptValue& value, ScriptMap& map);
void registerScriptMetaTypes(QScriptEngine* engine);
#endif // SCRIPTMAP_H

