/*************************************************************************************
* WEB322 - 2257 Project
* I declare that this assignment is my own work in accordance with the Seneca Academic
* Policy. No part of this assignment has been copied manually or electronically from
* any other source (including web sites) or distributed to other students.
*
* Student Name  : Alan Sanchez
* Student ID    : 121720247
* Student Email : aygarduno-sanchez@myseneca.ca
* Course/Section: WEB322/NEE
*
**************************************************************************************/

const path = require("path");
const express = require("express");
const app = express();

// EJS and layouts configuration
const expressLayouts = require("express-ejs-layouts");
app.set("view engine", "ejs");
app.use(expressLayouts);
app.set("layout", "layouts/main");

// Public folder for static assets
app.use(express.static("public"));

// Add your routes here
// e.g. app.get() { ... }

// Import the meal kit data module
const mealKitUtil = require("./modules/mealkit-util");

// Home page
app.get("/", (req, res) => {
    // Get all meal kits
    const allMealKits = mealKitUtil.getAllMealKits();
    // Get only featured meal kits
    const featuredMealKits = mealKitUtil.getFeaturedMealKits(allMealKits);
    // Pass featured meal kits to the view
    res.render("home", { featuredMealKits });
});

// On-the-menu page
app.get("/on-the-menu", (req, res) => {
    // Get all meal kits
    const allMealKits = mealKitUtil.getAllMealKits();
    // Group meal kits by category
    const mealKitsByCategory = mealKitUtil.getMealKitsByCategory(allMealKits);
    // Pass grouped meal kits to the view
    res.render("on-the-menu", { mealKitsByCategory });
});

// Registration page
app.get("/sign-up", (req, res) => {
    res.render("sign-up");
});

// Login page
app.get("/log-in", (req, res) => {
    res.render("log-in");
});





// This use() will not allow requests to go beyond it
// so we place it at the end of the file, after the other routes.
// This function will catch all other requests that don't match
// any other route handlers declared before it.
// This means we can use it as a sort of 'catch all' when no route match is found.
// We use this function to handle 404 requests to pages that are not found.
app.use((req, res) => {
    res.status(404).send("Page Not Found");
});

// This use() will add an error handler function to
// catch all errors.
app.use(function (err, req, res, next) {
    console.error(err.stack)
    res.status(500).send("Something broke!")
});


// *** DO NOT MODIFY THE LINES BELOW ***

// Define a port to listen to requests on.
const HTTP_PORT = process.env.PORT || 8080;

// Call this function after the http server starts listening for requests.
function onHttpStart() {
    console.log("Express http server listening on: " + HTTP_PORT);
}
  
// Listen on port 8080. The default port for http is 80, https is 443. We use 8080 here
// because sometimes port 80 is in use by other applications on the machine
app.listen(HTTP_PORT, onHttpStart);