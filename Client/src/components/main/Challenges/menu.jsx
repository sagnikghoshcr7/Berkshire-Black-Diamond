import React, { Component } from "react";
import "./menu.css";

class Menu extends Component {
  render() {
    return (
      <ul className="menu-industries">
        <li className="menu-li">All Industries</li>
        <li className="menu-li">Technology</li>
        <li className="menu-li">Financial</li>
        <li className="menu-li">Oil</li>
        <li className="menu-li">Food</li>
      </ul>
    );
  }
}

export default Menu;
