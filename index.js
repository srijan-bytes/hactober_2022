// library for express
const express = require("express");

const app = express();

// body parser
app.use(bodyParser.urlencoded({
  extended: true
}));

app.use(express.static("public"));

//server hosted on port 3000
app.listen(3000, function() {
  console.log("Server started on port 3000");
});
