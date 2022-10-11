import React from 'react';
import Card from '../../components/card';
import "./style.css";
import { NavLink } from 'react-router-dom';

const  Home = (props) => {
    return (
        <Card style = {{padding : "10px"}}>
            <div className = "hearder">
            <div className ="home-header">
                <p className = "header-box">
            every thing is fine when there is sunshine</p>
            </div>
            <div className="round-navbar">
               
               <NavLink to ="/summer-drinks" ><img className = "round-menu" alt = "go to ice-cream" src = {require("./../../images/main-coldrink.png")}></img></NavLink  >
               <NavLink to = "/summer-food" ><img className = "round-menu" alt = "go to ice-cream" src = {require("./../../images/main-foodbowl.png")}></img></NavLink  >
            </div>
            <div className="website-info">
            <h2>About the website</h2>
            <p>summer is all about sun shine, tan, sweet memories, chilled drinks, and yummy food, in this page you will find some easy and super yummy recipes that will boost your 
                mood "HAPPY SUMMERS".
            </p>
            </div>
            </div>
        </Card>
    );
}
 
export default  Home;