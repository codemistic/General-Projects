import React from "react";
import { Routes, Route, Link } from "react-router-dom";
import { Layout, Typography, Space } from "antd";

import {
  Exchanges,
  Homepage,
  News,
  Cryptocurrencies,
  CryptoDetails,
  Navbar,
} from "./components";
import "./App.css";

const App = () => (
  <div className="app">
    <div className="navbar">
      <Navbar />
    </div>
    <div className="main">
      <Layout>
        <div className="routes">
          <Routes>
            <Route exact path="/" element={<Homepage />}></Route>
            <Route exact path="/exchanges" element={<Exchanges />}></Route>
            <Route
              exact
              path="/cryptocurrencies"
              element={<Cryptocurrencies />}
            ></Route>
            <Route
              exact
              path="/crypto/:coinId"
              element={<CryptoDetails />}
            ></Route>
            <Route exact path="/news" element={<News />}></Route>
          </Routes>
        </div>
      </Layout>
      <div className="footer">
        <Typography.Title
          level={5}
          style={{ color: "white", textAlign: "center" }}
        >
          <Link to="/"> RapidCrypto Inc.</Link>
          <br />
          Copyright © 2022 | Kaushik Sharma
        </Typography.Title>
        <Space>
          <Link to="/">Home</Link>
          <Link to="/exchanges">Exchanges</Link>
          <Link to="/news">News</Link>
        </Space>
      </div>
    </div>
  </div>
);

export default App;
