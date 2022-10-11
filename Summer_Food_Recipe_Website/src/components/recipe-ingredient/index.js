import React from 'react';
import "./style.css";
import foodRecipes from './../../data/summer-food.json';
import DrinkRecipes from './../../data/summer-drink.json';
import Recipe from './../../containers/food-recipe/index';


const RecipeIngredient = ({id, data}) => {
     
  let Recipes = {};
   if(data == "summer-food")
   Recipes = {...foodRecipes};
   else if(data == "summer-drink")
   Recipes = {...DrinkRecipes};
   

    const recipe = Recipes.data.find(recipe => recipe.id == id);

    return ( <div className ="recipe-ingredient"> 
        <h2>ingredients</h2>
        <ul>
      {
          recipe.recipeIngredients.map( ingredient => (<li>{ingredient}
            </li>
          ))
      }
      </ul>
    </div> );
}
 
export default RecipeIngredient;