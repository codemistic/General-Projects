import React from 'react';
import './style.css';
import { NavLink } from 'react-router-dom';

const Navbar = (props) => {
    return ( 
        <div className = "navbar">
           <ul className = "menu">
               <li><NavLink className = "menu-item" to = "/">Home</NavLink ></li>
               <li><NavLink className = "menu-item" to = "/about-me">about me</NavLink ></li>
               <li><NavLink className = "menu-item" to = "/summer-food">summer food</NavLink ></li>
               <li><NavLink className = "menu-item" to = "/summer-drinks">summer Drinks</NavLink ></li>
           </ul>
        </div>
     );
}
 
export default Navbar;