// modules/mealkit-util.js

// Local array of meal kits (do not export)
const mealkits = [
    {
        title: "Chocolate Cake",
        includes: "Chocolate sponge, ganache, cocoa powder",
        description: "Rich and moist chocolate cake with creamy ganache.",
        category: "Classic Desserts",
        price: 15.99,
        cookingTime: 45,
        servings: 8,
        imageUrl: "/images/chocolate-cake.jpg",
        featuredMealKit: true        
    },
    {
        title: "Strawberry Cheesecake",
        includes: "Cream cheese, strawberries, graham crust",
        description: "Creamy cheesecake topped with fresh strawberries.",
        category: "Classic Desserts",
        price: 17.99,
        cookingTime: 60,
        servings: 10,
        imageUrl: "/images/strawberry-cheesecake.jpg",
        featuredMealKit: true
    },
    {
        title: "Tiramisu",
        includes: "Ladyfingers, espresso, mascarpone",
        description: "Italian classic with coffee-soaked ladyfingers and mascarpone cream.",
        category: "International Sweets",
        price: 18.99,
        cookingTime: 30,
        servings: 6,
        imageUrl: "/images/tiramisu.jpg",
        featuredMealKit: false
    },
    {
        title: "French Crème Brûlée",
        includes: "Vanilla custard, caramelized sugar",
        description: "Classic French dessert with a creamy custard base and crisp caramel top.",
        category: "International Sweets",
        price: 15.99,
        cookingTime: 50,
        servings: 6,
        imageUrl: "/images/creme-brulee.jpg",
        featuredMealKit: true
    },
    {
        title: "Carrot Cake",
        includes: "Carrots, walnuts, cream cheese frosting",
        description: "Moist carrot cake with crunchy walnuts and rich cream cheese frosting.",
        category: "Classic Desserts",
        price: 16.99,
        cookingTime: 60,
        servings: 10,
        imageUrl: "/images/carrot-cake.jpg",
        featuredMealKit: false
    },
    {
        title: "Apple Pie",
        includes: "Apples, cinnamon, pie crust",
        description: "Traditional apple pie with a flaky crust and spiced apple filling.",
        category: "Classic Desserts",
        price: 14.99,
        cookingTime: 70,
        servings: 8,
        imageUrl: "/images/apple-pie.jpg",
        featuredMealKit: false
    },
    {
        title: "Black Forest Cake",
        includes: "Chocolate sponge, cherries, whipped cream",
        description: "German chocolate cake layered with cherries and whipped cream.",
        category: "International Sweets",
        price: 19.99,
        cookingTime: 90,
        servings: 12,
        imageUrl: "/images/black-forest-cake.jpg",
        featuredMealKit: true
    },
    {
        title: "Rice Pudding",
        includes: "Rice, milk, cinnamon, vanilla",
        description: "Creamy rice pudding with a hint of vanilla and cinnamon.",
        category: "Traditional Sweets",
        price: 10.99,
        cookingTime: 40,
        servings: 6,
        imageUrl: "/images/rice-pudding.jpg",
        featuredMealKit: false
    },
    {
        title: "Flan",
        includes: "Eggs, milk, sugar, vanilla",
        description: "Silky smooth caramel custard with a rich caramel sauce.",
        category: "Traditional Sweets",
        price: 12.99,
        cookingTime: 120,
        servings: 8,
        imageUrl: "/images/flan.jpg",
        featuredMealKit: false
    },
    {
        title: "Key Lime Pie",
        includes: "Key limes, graham crackers, condensed milk",
        description: "Tangy and creamy Key lime pie with a buttery graham crust.",
        category: "Classic Desserts",
        price: 15.99,
        cookingTime: 45,
        servings: 8,
        imageUrl: "/images/key-lime-pie.jpg",
        featuredMealKit: true
    },
    {
        title: "Brownies",
        includes: "Almond flour, cocoa, chocolate chips",
        description: "Fudgy brownies made with gluten-free ingredients.",
        category: "Gluten-Free Desserts",
        price: 16.99,
        cookingTime: 40,
        servings: 12,
        imageUrl: "/images/brownies.jpg",
        featuredMealKit: false
    },
    {
        title: "Red Velvet Cake",
        includes: "Red velvet sponge, cream cheese frosting, cocoa powder",
        description: "Classic red velvet cake with rich cream cheese frosting.",
        category: "Classic Desserts",
        price: 18.99,
        cookingTime: 55,
        servings: 10,
        imageUrl: "/images/red-velvet-cake.jpg",
        featuredMealKit: true
    }
];

// Export function to get all meal kits
function getAllMealKits() {
    return mealkits;
}

// Export function to get only featured meal kits
function getFeaturedMealKits(mealkitsArr) {
    return mealkitsArr.filter(kit => kit.featuredMealKit);
}

// Export function to group meal kits by category
function getMealKitsByCategory(mealkitsArr) {
    const grouped = {};
    mealkitsArr.forEach(kit => {
        if (!grouped[kit.category]) grouped[kit.category] = [];
        grouped[kit.category].push(kit);
    });
    return Object.keys(grouped).map(categoryName => ({
        categoryName,
        mealKits: grouped[categoryName]
    }));
}

module.exports = {
    getAllMealKits,
    getFeaturedMealKits,
    getMealKitsByCategory
};
