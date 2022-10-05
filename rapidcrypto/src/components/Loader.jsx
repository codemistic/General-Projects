import { ThreeDots } from "react-loader-spinner";

const Loader = () => {
  return (
    <>
      <ThreeDots
        height="50"
        width="50"
        radius="9"
        color="black"
        ariaLabel="three-dots-loading"
        wrapperStyle
        wrapperClass
      />
    </>
  );
};

export default Loader;
