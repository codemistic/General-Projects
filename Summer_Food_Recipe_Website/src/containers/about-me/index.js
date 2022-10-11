import React from 'react';
import "./style.css";
import Card from '../../components/card';

const AboutMe = (props) => {
    return ( 
        <Card style ={{padding : "10px"}}>
    <div className="about-container">
        <h2>a litte about me</h2>
      <div className="image-box">
      <img alt="me" src={require("./../../images/rashika.jpg")}/>
      </div>
      <div>
      <p >Hello everyone, its me Rashika happy summer everyone. Like any other season summer brings lots of fun activities, water parks visit, beach hats and tan. But for some people its still a season of sweat and
            getting bore at home. But today in my page i am sharing a bunch of easy and super yummy summer delights, which are not just fun to prepare but are also yummy!!!!.</p>
            <p>
              from sandwiches to soda there is a room for everything .I am a front-end developer and very passionate about food and how to add more fun in it some of the recipes are my own and others are inspired by my mom 
              and from my sweet summer vacation memories hope you all like it. These are recepies shared with love.
              Have fun making them."Happy summers"
        </p>
      </div>
    </div> 
    </Card>);
}
 
export default AboutMe;