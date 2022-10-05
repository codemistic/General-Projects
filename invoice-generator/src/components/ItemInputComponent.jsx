import React from 'react';

export const ItemInputComponent = (props) => {
    return (
        <div className='my-1 flex-nowrap input-group'>
            <input
                className='form-control'
                placeholder={props.placeholder}
                name={props.name}
                value={props.val}
                onChange={(e) => props.itemChangeHandler(e, props.index)}
                required
            />
        </div>
    );
};
