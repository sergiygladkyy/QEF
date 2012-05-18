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
