

//requires

const express = require("express");


const app = express();


app.use(bodyParser.urlencoded({
  extended: true
}));
app.use(express.static("public"));

//server
app.listen(3000, function() {
  console.log("Server started on port 3000");
});
