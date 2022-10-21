const db = require("../models");
const config = require("../config/auth.config");
const { product: Product, role: Role, refreshToken: RefreshToken } = db;

const Op = db.Sequelize.Op;

// Add Product to Database
exports.addProduct = (req, res) => {
    Product.create({
      name: req.body.name,
      description: req.body.description,
      price: req.body.price
    })
      .then(prod => {
        if (prod) {
            res.status(200).send({
                id: prod.id,
                name: prod.name,
                description: prod.description,
                price: prod.price
              });
        } else {
            res.status(404).send({ message: "Cannot add product." });
        }
      })
      .catch(err => {
        res.status(500).send({ message: err.message });
      });
};

// Update Product to Database
exports.updateProduct = (req, res) => {
    Product.findOne({
        where: {
          id: req.body.id
        }
      })
        .then(async (product) => {
          if (!product) {
            return res.status(404).send({ message: "Product Not found." });
          }
          Product.update({
            name: req.body.name,
            description: req.body.description,
            price: req.body.price
          },
          {where : {
            id: req.body.id
          }})
            .then(prod => {
              if (prod) {
                  res.status(200).send({
                      message: `Product ${req.body.id} updated successfully`
                });
              } else {
                  res.status(404).send({ message: "Cannot update product." });
              }
            })
        })
        .catch(err => {
            res.status(500).send({ message: err.message });
        });
};

// Delete Product from database
exports.deleteProduct = (req, res) => {
    Product.findOne({
        where: {
          id: req.query.id
        }
      })
        .then(async (product) => {
          if (!product) {
            return res.status(404).send({ message: "Product Not found." });
          }
          Product.destroy({
              where : {
                id: req.query.id
            }
            })
            .then(prod => {
              if (prod) {
                  res.status(200).send({
                      message: `Product ${req.query.id} deleted successfully`
                });
              } else {
                  res.status(404).send({ message: "Cannot delete product." });
              }
            })
        })
        .catch(err => {
            res.status(500).send({ message: err.message });
        });
};

// Get all product list
exports.allProducts = (req, res) => {
    Product.findAll(
        {
            attributes:['name', 'price']
        }
    )
        .then(products => {
            if (products) {
                res.status(200).send({
                    products
                });
            } else {
                res.status(404).send({ message: "Product list not found." });
            }
        })
        .catch(err => {
            res.status(500).send({ message: err.message });
        });
};

// Get product details by id
exports.productById = (req, res) => {
    Product.findOne({
        where: {
          id: req.query.id
        }
      })
        .then(prod => {
            if (prod) {
                res.status(200).send({
                    prod
            });
            } else {
                res.status(404).send({ message: "Cannot find product product details." });
            }
        })
        .catch(err => {
            res.status(500).send({ message: err.message });
        });
};