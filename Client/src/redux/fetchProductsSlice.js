import { createAsyncThunk, createSlice } from "@reduxjs/toolkit";
import axios from "axios";

//dispatcher
export const getProducts = createAsyncThunk('fetchProductsThunk', async () => {
    try {
        const response = await axios.get("http://localhost:9191/products");
        return response.data;
    } catch (error) {
        return error;
    }
})

//slice
export const getProductsSlice = createSlice({
    name: 'fetchProductsSlice',
    initialState: {
        data: [],
        status: 'idle',
        error: null
    },
    extraReducers: {
        [getProducts.pending]: (state, action) => {
            state.data = [];
            state.status = 'loading';
            state.error = null;
        },
        [getProducts.fulfilled]: (state, action) => {
            state.data = action.payload;
            state.status = 'success';
            state.error = null;
        },
        [getProducts.rejected]: (state, action) => {
            state.data = [];
            state.status = 'fail';
            state.error = 'error';
        },
    }
})

export default getProductsSlice.reducer;