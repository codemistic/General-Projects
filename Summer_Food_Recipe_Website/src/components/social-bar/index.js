import React from 'react';
import './style.css';
import { NavLink } from 'react-router-dom';

const SocialBar = () => {
    return (
        <div className = "social-bar">
         <span className = "summer-delights">summer delights</span>
         <div className = "social-icon">
           <a href ="mailto:rashikarawat01@gamil.com"><img  className="email-header" alt ="mail" src ={require("./../../images/email-header.png")}/></a>
           <a href="https://twitter.com/Rashika25199287"><img alt ="mail" src ={require("./../../images/twitter-icon.png")}/></a>
           <a href ="http://www.instagram.com/_r_rawat_"><img alt ="mail" src ={require("./../../images/insta-icon.png")}/></a>
         </div>
        </div>
      );
}
 
export default SocialBar;