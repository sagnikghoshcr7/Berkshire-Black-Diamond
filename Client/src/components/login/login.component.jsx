import React, { useState } from 'react';
import { connect } from 'react-redux';

import FormInput from '../form-input/form-input.component';
import CustomButton from '../custom-button/custom-button.component';

import {
  googleLoginStart,
  emailLoginStart
} from '../../redux/user/user.actions';

import {
  LoginContainer,
  LoginTitle,
  ButtonsBarContainer
} from './login.styles';

const Login = ({ emailLoginStart, googleLoginStart }) => {
  const [userCredentials, setCredentials] = useState({
    email: '',
    password: ''
  });

  const { email, password } = userCredentials;

  const handleSubmit = async event => {
    event.preventDefault();

    emailLoginStart(email, password);
  };

  const handleChange = event => {
    const { value, name } = event.target;

    setCredentials({ ...userCredentials, [name]: value });
  };

  return (
    <LoginContainer>
      <LoginTitle>I already have an account</LoginTitle>
      <span>Sign in with your email and password</span>

      <form onSubmit={handleSubmit}>
        <FormInput
          name='email'
          type='email'
          handleChange={handleChange}
          value={email}
          label='email'
          required
        />
        <FormInput
          name='password'
          type='password'
          value={password}
          handleChange={handleChange}
          label='password'
          required
        />
        <ButtonsBarContainer>
          <CustomButton type='submit'> Sign in </CustomButton>
          <CustomButton
            type='button'
            onClick={googleLoginStart}
            isGoogleLogin
          >
            Sign in with Google
          </CustomButton>
        </ButtonsBarContainer>
      </form>
    </LoginContainer>
  );
};

const mapDispatchToProps = dispatch => ({
  googleLoginStart: () => dispatch(googleLoginStart()),
  emailLoginStart: (email, password) =>
    dispatch(emailLoginStart({ email, password }))
});

export default connect(
  null,
  mapDispatchToProps
)(Login);
