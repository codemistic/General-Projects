import React from 'react';
import Card from '../../components/card';
import "./style.css"
import RecipeIngredient from '../../components/recipe-ingredient';
import RecipeSteps from '../../components/recipe-steps';
const Recipe = (props) => {
  const Id = props.match.params.id;
   const url =props.match.url;
   let data = "";
   if(url==`/summer-food/${Id}`)
      data = "summer-food";
   else if(url==`/summer-drink/${Id}`)
      data = "summer-drink";
 console.log(data);
  
    

    return ( <div className = "re">
         <div className="re-ingredient">
           <RecipeIngredient
           id ={Id}
           data={data}/>
         </div>
         <div className="re-steps" >
            <RecipeSteps
            id ={Id}
            data={data}/>
         </div>
    </div> );
}
 
export default Recipe;