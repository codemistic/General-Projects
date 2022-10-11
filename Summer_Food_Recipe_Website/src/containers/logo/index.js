import React from 'react';
import "./style.css";

const Logo = (props) => {
    return ( <div className = "logo">
        <div>
        <img alt ="logo" src ={require("./../../images/RockArt-GeorgeSpiral-Sun.svg")}/>
        </div>
        Summer Delights
    </div> );
}
 
export default Logo;