class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        
        a = []
        re = dict()
        result = []
        
        for path in paths:
            a.append(list(path.split()))
            
        
        for files in a:
            directory = files[0]
            for file in files[1:]:
                filename, content = file.split( '(' )
                content = content[:-1]
                new_file_path = directory+'/'+filename
                if content in re :
                    re[content].append(new_file_path)
                else:
                    re[content] = [new_file_path]
      
        return list(filter(lambda elem: len(elem) > 1, list(re.values())))