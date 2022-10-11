import React from 'react';
import "./style.css";
import Card from '../../components/card';

const NotFound = (props) => {
    return (  <div className="error-box">
        <Card style ={{height: "70vh"}}>
        <h2> 404 Not Found</h2>
        </Card>
    </div>);
}
 
export default NotFound;