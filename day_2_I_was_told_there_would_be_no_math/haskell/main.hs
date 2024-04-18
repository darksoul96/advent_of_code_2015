{-
    Box dimensions
    length, width, height

    Every present is a box -> Area = 2*l*w + 2*w*h + 2*h*l
    Extra paper = Area of smallest side
-}

import System.IO
import Data.Char

main :: IO ()
main = do
    fileHandle <- openFile "../input.txt" ReadMode
    contents <- hGetContents fileHandle
    let singlewords = words contents
    f singlewords
    hClose fileHandle


-- f :: [String] -> void
-- f [] = print [(0,0,0)]
-- f (x:xs) = 
--     print [(5,5,5)]
--     f xs
