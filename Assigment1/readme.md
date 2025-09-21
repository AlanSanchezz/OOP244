# WEB322 - Assignment 1: Chalet Dessert Meal Kits

I declare that this assignment is my own work in accordance with the Seneca Academic
Policy. No part of this assignment has been copied manually or electronically from
any other source (including web sites) or distributed to other students.

## Project Description
Chalet is a dessert meal kit delivery website featuring a modern, responsive design. The site showcases various dessert meal kits organized by categories, with detailed information including ingredients, cooking times, servings, and pricing.

## Features
- Responsive design with Bootstrap 5
- Hero section with video background
- Interactive meal kit cards with hover effects
- Category-based navigation
- User registration and login pages
- Modern animations and visual effects

## Student Information
Student Name  : Alan Sanchez
Student ID    : 121720247
Student Email : aygarduno-sanchez@myseneca.ca
Course/Section: WEB322/NEE

## Installation Instructions

### Prerequisites
- Node.js (version 14 or higher)
- npm (Node Package Manager)

### Setup Steps
1. Clone or download the project files
2. Open terminal in the project directory
3. Install dependencies:
   ```bash
   npm install express ejs express-ejs-layouts
   ```
4. Start the server:
   ```bash
   node server.js
   ```
5. Open your browser and go to `http://localhost:8080`

## Dependencies
- **Express.js**: Web framework for Node.js
- **EJS**: Templating engine for dynamic content
- **express-ejs-layouts**: Layout support for EJS templates
- **Bootstrap 5**: CSS framework for responsive design

## File Structure
```
Assignment1/
├── server.js              # Main server file
├── modules/
│   └── mealkit-util.js    # Data module with meal kit information
├── views/
│   ├── layouts/
│   │   └── main.ejs       # Main layout template
│   ├── partials/
│   │   ├── navbar.ejs     # Navigation bar
│   │   ├── footer.ejs     # Footer
│   │   └── mealkit.ejs    # Meal kit card template
│   ├── home.ejs           # Home page
│   ├── on-the-menu.ejs    # Menu page
│   ├── sign-up.ejs        # Registration page
│   └── log-in.ejs         # Login page
├── public/
│   ├── css/
│   │   └── styles.css     # Custom styles
│   ├── images/            # Image assets
│   └── videos/            # Video assets
└── readme.md              # This file
```

## Usage
- Navigate to different pages using the navigation bar
- View featured desserts on the home page
- Browse all desserts by category on the "On the Menu" page
- Hover over meal kit images to see alternate views
- Test responsive design by resizing browser window

## Access from Other Devices
To access the site from other devices on the same network:
1. Find your local IP address using `ipconfig` (Windows) or `ifconfig` (Mac/Linux)
2. Access the site using `http://YOUR_IP_ADDRESS:8080`

For external access, use ngrok:
1. Install ngrok: `npm install -g ngrok`
2. Run: `ngrok http 8080`
3. Use the provided public URL

## Project URLs
In assignment 2, you will publish to GitHub, provide the link below:
GitHub Repo   : https://github.com/<repo_name>/

In assignment 3, you will publish to Vercel, provide the link below:
Vercel Domain : https://<app_name>.vercel.app/


