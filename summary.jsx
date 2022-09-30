import React, { Component } from "react";
import "./summary.css";

class Summary extends Component {
  render() {
    return (
      <div className="summary-box">
        <table className="summary-table">
          <tbody>
            <tr>
              <td>No of Stocks:</td>
              <td>{this.props.stocks.length}</td>
            </tr>
            <tr>
              <td>Equities:</td>
              <td>$100,000</td>
            </tr>
            <tr>
              <td>Cash:</td>
              <td>$50,000</td>
            </tr>
            <tr>
              <td>Total Portfolio:</td>
              <td>$150,000</td>
            </tr>
          </tbody>
        </table>
      </div>
    );
  }
}

export default Summary;
