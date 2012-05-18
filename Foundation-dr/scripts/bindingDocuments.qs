function documents_Binding()
{
this.Currency_exchange = new document_Currency_exchange_Binding (Currency_exchange);
this.Car_order = new document_Car_order_Binding (Car_order);
this.Reception = new document_Reception_Binding (Reception);
}
var Documents = new documents_Binding();
