import React from 'react';

import recipes from './../../data/summer-drink.json';
import RecipePortal from './../../components/recipe-portal/index';

const SummerDrinks = (props) => {
    
      const recipe = recipes.data;
 return (  <RecipePortal
    recipe ={recipe}/>);
}
 
export default SummerDrinks ;