function catalog_Persons_Binding(x)
{

this.object = x;
this.map = x.attributes();
this.age;
this.code;
this.description;
this.f_name;
this.l_name;
this.Write = function()
{
this.object.setAttribute("age", this.age);
this.object.setAttribute("code", this.code);
this.object.setAttribute("description", this.description);
this.object.setAttribute("f_name", this.f_name);
this.object.setAttribute("l_name", this.l_name);
}
this.GetRef = function()
{
return this;
}
this.Safe = function()
{
this.object.setAttribute("age", this.age);
this.object.setAttribute("code", this.code);
this.object.setAttribute("description", this.description);
this.object.setAttribute("f_name", this.f_name);
this.object.setAttribute("l_name", this.l_name);
this.object.serializeToTheDB();
}
}
function catalog_Colors_Binding(x)
{

this.object = x;
this.map = x.attributes();
this.code;
this.description;
this.Write = function()
{
this.object.setAttribute("code", this.code);
this.object.setAttribute("description", this.description);
}
this.GetRef = function()
{
return this;
}
this.Safe = function()
{
this.object.setAttribute("code", this.code);
this.object.setAttribute("description", this.description);
this.object.serializeToTheDB();
}
}
function document_Currency_exchange_Binding(x)
{

this.object = x;
this.currency;
this.datetime;
this.number;
this.Write = function()
{
this.object.setAttribute("currency", this.currency);
this.object.setAttribute("datetime", this.datetime);
this.object.setAttribute("number", this.number);
}
this.Add = function()
{
this.object.setAttribute("currency", "");
this.object.setAttribute("datetime", "");
this.object.setAttribute("number", "");
return this;
}
}
function document_Car_order_Binding(x)
{

this.object = x;
this.datetime;
this.model;
this.number;
this.price;
this.year;
this.Write = function()
{
this.object.setAttribute("datetime", this.datetime);
this.object.setAttribute("model", this.model);
this.object.setAttribute("number", this.number);
this.object.setAttribute("price", this.price);
this.object.setAttribute("year", this.year);
}
this.Add = function()
{
this.object.setAttribute("datetime", "");
this.object.setAttribute("model", "");
this.object.setAttribute("number", "");
this.object.setAttribute("price", "");
this.object.setAttribute("year", "");
return this;
}
}
function document_Reception_Binding(x)
{

this.object = x;
this.age;
this.country;
this.datetime;
this.l_name;
this.number;
this.s_name;
this.Write = function()
{
this.object.setAttribute("age", this.age);
this.object.setAttribute("country", this.country);
this.object.setAttribute("datetime", this.datetime);
this.object.setAttribute("l_name", this.l_name);
this.object.setAttribute("number", this.number);
this.object.setAttribute("s_name", this.s_name);
}
this.Add = function()
{
this.object.setAttribute("age", "");
this.object.setAttribute("country", "");
this.object.setAttribute("datetime", "");
this.object.setAttribute("l_name", "");
this.object.setAttribute("number", "");
this.object.setAttribute("s_name", "");
return this;
}
}
function register_Records_Currency_exchange_Binding(x)
{

this.object = x;
this.map = x.attributes();
this.currency_after;
this.currency_before;
this.Write = function()
{
this.object.setAttribute("currency_after", this.currency_after);
this.object.setAttribute("currency_before", this.currency_before);
}
this.Add = function()
{
this.object.setAttribute("currency_after", "");
this.object.setAttribute("currency_before", "");
return this;
}
}
function register_Records_Car_order_Binding(x)
{

this.object = x;
this.map = x.attributes();
this.model;
this.price;
this.year;
this.Write = function()
{
this.object.setAttribute("model", this.model);
this.object.setAttribute("price", this.price);
this.object.setAttribute("year", this.year);
}
this.Add = function()
{
this.object.setAttribute("model", "");
this.object.setAttribute("price", "");
this.object.setAttribute("year", "");
return this;
}
}
function register_Records_Reception_Binding(x)
{

this.object = x;
this.map = x.attributes();
this.age;
this.country;
this.l_name;
this.s_name;
this.Write = function()
{
this.object.setAttribute("age", this.age);
this.object.setAttribute("country", this.country);
this.object.setAttribute("l_name", this.l_name);
this.object.setAttribute("s_name", this.s_name);
}
this.Add = function()
{
this.object.setAttribute("age", "");
this.object.setAttribute("country", "");
this.object.setAttribute("l_name", "");
this.object.setAttribute("s_name", "");
return this;
}
}
function catalogs_Binding()
{
this.Persons = new catalog_Persons_Binding (Persons);
this.Colors = new catalog_Colors_Binding (Colors);
}
var Catalogs = new catalogs_Binding();
function documents_Binding()
{
this.Currency_exchange = new document_Currency_exchange_Binding (Currency_exchange);
this.Car_order = new document_Car_order_Binding (Car_order);
this.Reception = new document_Reception_Binding (Reception);
}
var Documents = new documents_Binding();
function movements_Binding()
{
this.Records_Currency_exchange = new register_Records_Currency_exchange_Binding (Records_Currency_exchange);
this.Records_Car_order = new register_Records_Car_order_Binding (Records_Car_order);
this.Records_Reception = new register_Records_Reception_Binding (Records_Reception);
}
var Movements = new movements_Binding();
