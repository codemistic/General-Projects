import React from 'react';
import recipes from './../../data/summer-food.json';
import RecipePortal from './../../components/recipe-portal/index';

const SummerFood = (props) => {
    
      const recipe = recipes.data;
 return (  <RecipePortal
    recipe ={recipe}/>);
}
 
export default SummerFood;