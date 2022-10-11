import React from 'react';
import "./style.css";
import Card from '../../components/card';



const Footer = (props) => {
    return ( <div className="footer">
        <Card style = {{marginTop : "20px", padding: "40px", backgroundColor:"rgb(253, 114, 33)"}}>
            <div className="footer-items">
        <div>
           <h2>Summer Delights</h2>
           <div className="email-contact">
           <img className="email" alt = "email" src = {require("./../../images/email-footer.png")}/>
           <a href="mailto:rashikarawat01@gamil.com">rashikarawat01@gmail.com</a>
        </div>
        </div>
        <div className="greetings">
       <p>"feel free to write any suggestions and yummy recipes for the page"</p>
        </div>
        </div>
        </Card>
    </div> 
    );
}
 
export default Footer;