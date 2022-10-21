const { authJwt } = require("../middleware");
const { productMiddleware } = require("../middleware")
const controller = require("../controllers/product.controller");

module.exports = function(app) {
  app.use(function(req, res, next) {
    res.header(
      "Access-Control-Allow-Headers",
      "x-access-token, Origin, Content-Type, Accept"
    );
    next();
  });

  app.post(
    "/api/addproduct",
    [authJwt.verifyToken, authJwt.isAdmin],
    controller.addProduct
  );
  app.put(
    "/api/updateproduct",
    [authJwt.verifyToken, authJwt.isAdmin],
    controller.updateProduct
  );
  app.delete(
    "/api/deleteproduct",
    [authJwt.verifyToken, authJwt.isAdmin],
    controller.deleteProduct
  );
  app.get(
    "/api/productlist",
    controller.allProducts
  );
  app.get(
    "/api/productbyid",
    controller.productById
  );
};