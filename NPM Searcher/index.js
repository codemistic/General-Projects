const axios = require("axios");

const readline = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

readline.question("Enter npm package name: ", (name) => {
  readline.close();
  axios
    .get(`https://api.npms.io/v2/search?q=${name}`)
    .then((response) => {
      console.log("");
      console.log("The 3 most appropriate packages are: ");
      for (let i = 0; i < 3; i++) {
        console.log("> ", response.data.results[i].package.name);
        console.log("> ", response.data.results[i].package.description);
        console.log("> ", response.data.results[i].package.version);
        console.log("> ", response.data.results[i].package.links.npm);
        console.log("");
      }
      console.log("Thanks for using my app :)");
    })
    .catch((error) => {
      console.log(
        "Oops, something went wrong. No appropriate packages found.\n",
        error
      );
    });
});
