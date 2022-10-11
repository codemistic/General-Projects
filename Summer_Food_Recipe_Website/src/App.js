import React from 'react';
import './App.css';

import SocialBar from './components/social-bar';
import Card from './components/card';
import Navbar from './components/nav-bar';
import Home from './containers/home';
import { BrowserRouter  as  Router, Route, Redirect, Switch } from 'react-router-dom';
import AboutMe from './containers/about-me/index';
import Logo from './containers/logo/index';
import SummerFood from './containers/summer-food/index';
import Recipe from './containers/food-recipe/index';
import SummerDrinks from "./containers/summer-drinks/index"
import Footer from './containers/footer';
import NotFound from './containers/error';


function App() {
  return (
     <Router>
         <div className="App">
        <SocialBar/>
      <Card >
        <Logo/>
        <Navbar/>
      </Card>
      <Switch>
       
      <Route path ="/" exact  component ={Home}/>
      <Route path ="/about-me" exact   component ={AboutMe}/>
      <Route path ="/summer-food" exact component ={SummerFood}/>
      <Route path ="/summer-drinks" exact component ={SummerDrinks }/>
      <Route path = "/summer-food/:id" exact component ={Recipe}/>
      <Route path = "/summer-drink/:id" exact component ={Recipe}/>
      <Route path="/not-found" exact component={NotFound}/>
      <Redirect to="/not-found"/>
    
       </Switch>
     
     
      </div>
      <Footer/>
       
      </Router>
  );
}

export default App;
