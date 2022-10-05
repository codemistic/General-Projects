import React from 'react';

export const ItemBillDetails = (props) => {
    return (
        <input
            type={props.type}
            placeholder={props.placeholder}
            className='form-control my-2'
            name={props.name}
            value={props.val}
            onChange={(e) =>
                props.setInput((prev) => ({
                    ...prev,
                    [e.target.name]: e.target.value
                }))
            }
            required
        />
    );
};
