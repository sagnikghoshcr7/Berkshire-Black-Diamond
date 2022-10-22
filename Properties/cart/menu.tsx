import React from 'react';
import { useIsCartEmpty, useFindCartItems } from 'src/components/hooks/cart';

export const MenuComponent = () => {
    const cartIsEmpty = useIsCartEmpty();
    const item = useFindCartItems('some-item-id');
    return (
        <>
            cartIsEmpty ? <div>Cart is Empty</div> :
            <div>
                Cart has some items
                <p>Found cart item: {item}</p>
            </div>
        </>
    );
};