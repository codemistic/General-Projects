import { Container, makeStyles, Typography } from "@material-ui/core";
import React from "react"
import Carousel from "./Carousel";
const useStyles = makeStyles(() => ({
  banner: {
    //   background:"red",
    backgroundImage: "url(./banner2.jpg)",
    minHeight: 400,
    paddingTop: 25,
},
bannerContent: {
    display: "flex",
    flexDirection: "coloumn",
    
    justifyContent: "space-around",
    
  },
  tagline: {
    display: "flex",
    height: "40%",
    flexDirection: "column",
    justifyContent: "center",
    textAlign: "center",
  },
}));

const Banner = () => {
  const classes = useStyles();
  return (
    <div className={classes.banner}>
      <Container classname={classes.bannerContent}>
        <div className={classes.tagline}>
          <Typography
            variant="h2"
            style={{
              fontWeight: "bold",
              marginBottom: 15,
              fontFamily: "Montserrat",
            }}
          >
            Crypto Hunter
            <Typography
              variant="subtitle2"
              style={{
                color: "darkgray",
                transform: "capitalize",
                fontFamily: "Montserrat",
              }}
            >
              Get all the info regarding your favorite Crypto Currency
            </Typography>
          </Typography>
        </div>
        <Carousel />
      </Container>
    </div>
  );
};

export default Banner;
