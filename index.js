// library for express
const express = require("express");
const bodyParser = require("body-parser");
const ejs = require("ejs");
const _ = require("lodash");
const mongoose = require('mongoose');

const app = express();

// body parser
app.use(bodyParser.urlencoded({
  extended: true
}));

app.use(express.static("public"));

mongoose.connect("mongodb://localhost:27017/projectDB", {
  useNewUrlParser: true
});

//server hosted on port 3000
app.listen(3000, function() {
  console.log("Server started on port 3000");
});
