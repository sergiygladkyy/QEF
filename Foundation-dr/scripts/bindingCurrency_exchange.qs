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
