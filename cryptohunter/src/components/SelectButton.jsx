// import { makeStyles } from "@material-ui/styles";
// import React from "react";

// const SelectButton = ({ children, selected, onClick }) => {
//   const useStyles = makeStyles({
//     selectbutton: {
//       border: "1px solid gold",
//       borderRadius: 5,
//       padding: 10,
//       paddingLeft: 20,
//       paddingRight: 20,
//       fontFamily: "Montserrat",
//       cursor: "pointer",
//       backgroundColor: selected ? "gold" : "",
//       color: selected ? "black" : "",
//       fontWeight: selected ? 700 : 500,
//       "&:hover": {
//         backgroundColor: "gold",
//         color: "black",
//       },
//       width: "22%",
//       //   margin: 5,
//     },
//   });
//   const classes = useStyles();

//   return (
//     <span className={classes.selectbutton} onClick={onclick}>
//       {children}
//     </span>
//   );
// };

// export default SelectButton;
import { makeStyles } from "@material-ui/core";

const SelectButton = ({ children, selected, onClick }) => {
  const useStyles = makeStyles({
    selectbutton: {
      border: "1px solid gold",
      borderRadius: 5,
      padding: 10,
      paddingLeft: 20,
      paddingRight: 20,
      fontFamily: "Montserrat",
      cursor: "pointer",
      backgroundColor: selected ? "gold" : "",
      color: selected ? "black" : "",
      fontWeight: selected ? 700 : 500,
      "&:hover": {
        backgroundColor: "gold",
        color: "black",
      },
      width: "22%",
      //   margin: 5,
    },
  });

  const classes = useStyles();

  return (
    <span onClick={onClick} className={classes.selectbutton}>
      {children}
    </span>
  );
};

export default SelectButton;