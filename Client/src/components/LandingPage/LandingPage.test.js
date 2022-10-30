import React from "react";
import { shallow } from "enzyme";
import LandingPage from "./LandingPage.component";

it("should render Landing Page component", () => {
  expect(shallow(<LandingPage />)).toMatchSnapshot();
});
