import React from "react";
import ReactDOM  from "react-dom";
import { BrowserRouter as Router } from "react-router-dom";
import 'antd/dist/antd.css';
import { Provider } from "react-redux";

import App from './App';
import store from './app/store';

ReactDOM.render(
<Router>
   <Provider store={store}>
      <App />
   </Provider>
</Router>, 
document.getElementById('root'));