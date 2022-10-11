import React from 'react';
import "./style.css";
import foodRecipes from './../../data/summer-food.json';
import DrinkRecipes from './../../data/summer-drink.json';


const RecipeSteps = ({id, data}) => {
  
  let Recipes = {};
  if(data == "summer-food")
  Recipes = {...foodRecipes};
  else if(data == "summer-drink")
  Recipes = {...DrinkRecipes};
  

    const recipe = Recipes.data.find(recipe => recipe.id == id);
   

    return (<div className ="recipe-steps">
        <h2>{recipe.recipeName}</h2>
        <div className ="recipe-image-solo">
        <img alt ="food" src ={require(`./../../images/${recipe.recipeImage}`)}/>
        </div>
        <div className="recipe-quide">{
        recipe.recipe.map( step => ( <p>{step}</p>
          ))
        }
        </div>
    </div>  );
}
 
export default RecipeSteps;